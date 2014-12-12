package server;



//Restore.java   
//tcp socket programming 
import java.io.*;
import java.net.*;
//imaging process 
import java.awt.*;   
import java.awt.event.*;   
import java.awt.image.*;   
import javax.swing.*;   

public class Server extends Frame {   
Image im,tmp;   
int iw,ih;   
int[] pixels;   

double [] newPixels;   
double [] newKernel;   

Complex [] complex;   
Complex [] comKernel;   

boolean flagLoad=false;   
boolean flagBlur=false;   

FFT2 fft2;   
IFFT2 ifft2;   
 
public Server(){   
  this.setTitle("Server");   
  Panel pdown;   
  Button load,blur,run,quit;   
 //add a window to listen events  
  addWindowListener(new WindowAdapter(){   
    public void windowClosing(WindowEvent e){   
      System.exit(0);   
    }   
  });   

  pdown = new Panel();   
  pdown.setBackground(Color.lightGray);   

  load=new Button("load");   
  blur=new Button("transform");   
  run = new Button("restore ");   
  quit=new Button("exit");   

  this.add(pdown,BorderLayout.SOUTH);   

  pdown.add(load);   
  pdown.add(blur);   
  pdown.add(run);   
  pdown.add(quit);   

  load.addActionListener(new ActionListener(){   
    public void actionPerformed(ActionEvent e){   
      jLoad_ActionPerformed(e);   
    }   
  });   

  blur.addActionListener(new ActionListener(){   
    public void actionPerformed(ActionEvent e){   
      jBlur_ActionPerformed(e);   
    }   
  });   

  run.addActionListener(new ActionListener(){   
    public void actionPerformed(ActionEvent e){   
      jRun_ActionPerformed(e);   
    }   
  });   

  quit.addActionListener(new ActionListener(){   
    public void actionPerformed(ActionEvent e){   
      jQuit_ActionPerformed(e);   
    }   
  });   
}   

public void jLoad_ActionPerformed(ActionEvent e){   
  //use media tracker to track the loading of image  
	System.out.println("Server: beging to load a blank image...");
  MediaTracker tracker = new MediaTracker(this);   
  im=Toolkit.getDefaultToolkit().getImage("Miss.jpg");   
  tracker.addImage(im,0);   

  //wait until image loading done   
  try{   
    tracker.waitForID(0);   
  }catch(InterruptedException e2){ e2.printStackTrace();}   

  //get the height and width of image 
  iw=im.getWidth(this);   
  ih=im.getHeight(this);   
  pixels=new int[iw*ih];   

  try{   
    PixelGrabber pg=new PixelGrabber(im,0,0,iw,ih,pixels,0,iw);   
    pg.grabPixels();   
  }catch (InterruptedException e3) {   
    e3.printStackTrace();   
  }   
 
   //make the pix in the array as a pic   
  ImageProducer ip=new MemoryImageSource(iw,ih,pixels,0,iw);   
  tmp=createImage(ip);   
  flagLoad=true;   
  repaint();   
  //create a blank pic 
  for(int i = 0; i<iw*ih; ++i){
	  pixels[i] = 0; 
  }
  ImageProducer temp_ip=new MemoryImageSource(iw,ih,pixels,0,iw);   
  tmp=createImage(temp_ip);   
}   

public void jBlur_ActionPerformed(ActionEvent e)   
{   
  if(flagLoad){   
   //blur the pic   
	
    newPixels=new double [iw*ih];   

    for(int i=0;i<ih;i++)   
    {   
      for(int j=0;j<iw;j++)   
      {   
        newPixels[i*iw+j]=pixels[i*iw+j]&0x00ffffff;   

      }   
    }   

    //initial   
    complex=new Complex[iw*ih];  
    //complete array of fft results 
    double [] FFT_res; 
    FFT_res = new double[iw*ih*2]; 

    for(int i=0;i<iw*ih;i++)   
    {   
      complex[i]=new Complex(0,0);   
    }   
    //------------------------------------ FFT ---------------------------------// 
    fft2=new FFT2();   
    fft2.setData(iw,ih,newPixels);   
    complex=fft2.getComplex();    
    newPixels=fft2.getPixels();   
    
    System.out.println("complex[512] = "+ complex[512].re()+"+i*"+complex[512].im());
    System.out.println("Lengths: "+newPixels.length);   
    System.out.println("Lengths: "+complex.length);
    System.out.println("iw*ih: "+iw*ih);
    

    for (int i = 0; i< FFT_res.length/2; ++i) {
      FFT_res[i*2] = complex[i].re();
      FFT_res[i*2+1] = complex[i].im();
    }

    
   //standardize 
    double max=newPixels[0];   
    for(int i=1;i<iw*ih;i++)   
    {   
      if(max<newPixels[i])   
      {   
        max=newPixels[i];   
      }   
    }  


    ColorModel cm=ColorModel.getRGBdefault();   

    for(int i=0;i<ih;i++)   
    {   
      for(int j=0;j<iw;j++)   
      {   

       pixels[i*iw+j]=(int)newPixels[i*iw+j]&0x00ffffff|0xff000000;
     }   
   }   

   ImageProducer ip=new MemoryImageSource(iw,ih,pixels,0,iw);   
   tmp=createImage(ip);   

   repaint();   
   flagBlur=true;   

 }else{   
   JOptionPane.showMessageDialog(null,"Please open a pic",   
     "Alert",JOptionPane.WARNING_MESSAGE);   
 }   

}   

public  void jRun_ActionPerformed(ActionEvent e){   
	System.out.println("Begin to restore the pic");
	iw = 512;
	ih = 512; 
	complex=new Complex[iw*ih];
  
	 for(int i=0;i<iw*ih;i++)   
	    {   
	      complex[i]=new Complex(0,0);   
	    } 
if(true){   
   
  //double[] ifft_data;
  //ifft_data = new double[iw*ih*2];
  //---------------------------------- RECIEVE DATA -----------------------------// 
   try{
         //create a new server socket 
         int serverPort = 3600;
         @SuppressWarnings("resource")
       
         ServerSocket serverSock = new ServerSocket(serverPort);
         //serverSock.bind(new InetSocketAddress("127.0.0.1", 3600));
         System.out.println("Begin to listen to clients.... ");
         Socket sock = serverSock.accept(); 
         System.out.println("accept the connection request from client\n");
         //recieve data from client
        ObjectInputStream ois = new ObjectInputStream(sock.getInputStream());
        double []ifft_data = (double[])ois.readObject(); //reader.readLine();
       
        System.out.println("recieving data size is: "+ifft_data.length);
        
  
        for (int i = 0; i< iw*ih; ++i ) {
            complex[i].set_re (ifft_data[i*2]);
            complex[i].set_im (ifft_data[i*2+1]);
            System.out.println("Server: !!! iffi data real is: "+complex[i].re());
            System.out.println("Server: iffi data image is: "+complex[i].im());
        }
        
        
        //send msg to client 
        ObjectOutputStream outputStream = new ObjectOutputStream(sock.getOutputStream());
        outputStream.writeObject("ACK: recieve data from client!\n"); 

   }catch (IOException ex) {
       ex.printStackTrace();

  }catch (ClassNotFoundException en) {
		// TODO Auto-generated catch block
		en.printStackTrace();
	}
  
  //------------------------------------ IFFT ---------------------------------//    
  pixels=new int[iw*ih];
  for(int i = 0; i<iw*ih; ++i){
	  pixels[i] = 0; 
  }
  
  newPixels=new double [iw*ih];      //restore the image 
  ifft2=new IFFT2();   
  ifft2.setData(iw,ih,complex);   
  newPixels=ifft2.getPixels();
  
  
  System.out.println("IFFT at server is end!");
  
  //standardize    
          double max=newPixels[0];   
          for(int i=1;i<iw*ih;i++)   
          {   
            if(max<newPixels[i])   
            {   
              max=newPixels[i];
              
            }   
          }  

          ColorModel cm=ColorModel.getRGBdefault();   

          for(int i=0;i<ih;i++)   
          {   
            for(int j=0;j<iw;j++)   
            {   
             pixels[i*iw+j]=(int)newPixels[i*iw+j]&0x00ffffff|0xff000000;
           }   
          }   

          
          ImageProducer ip=new MemoryImageSource(iw,ih,pixels,0,iw);   
          tmp=createImage(ip);   

          repaint();   
          }else{   
                      JOptionPane.showMessageDialog(null,"Please open a pic and transform!",   
                       "Alert",JOptionPane.WARNING_MESSAGE);   
              } 
          }   

public void jQuit_ActionPerformed(ActionEvent e){   
    //System.exit(0);   
JOptionPane op =new JOptionPane();   
int exit=op.showConfirmDialog(this,"Do you want to exit? ? ?","exit",JOptionPane.YES_NO_OPTION);   

if(exit==JOptionPane.YES_OPTION)   
{   
  System.exit(0);   

}else{ }   
}   

//call paint function to draw the pic   
public void paint(Graphics g){   
if(flagLoad){   
  g.drawImage(tmp,10,20,this);   
}else { }   
}   

//define main method, set the siz of window and display
public static void main(String[] args) {   
Server server = new Server();   
server.setLocation(50,50);   
server.setSize(500,400);   
server.show();   
}    
}  
