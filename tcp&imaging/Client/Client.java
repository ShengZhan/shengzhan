package Client;


//Restore.java   
//tcp socket programming 

import java.io.*;
import java.net.*;
//imaging process 
import java.awt.*;   
import java.awt.event.*;   
import java.awt.image.*;   

import javax.swing.*;   

public class Client extends Frame {   
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

  //constructor   
  public Client(){   
    this.setTitle("Client");   
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
     //track the loading of pic  
	System.out.println("Client: beging to load the image...");
	MediaTracker tracker = new MediaTracker(this);   
    im=Toolkit.getDefaultToolkit().getImage("Miss.jpg");   
    tracker.addImage(im,0);   

    //wait untill the pic loading   
    try{   
      tracker.waitForID(0);   
    }catch(InterruptedException e2){ e2.printStackTrace();}   

     //get the hight and weight of pic   
    iw=im.getWidth(this);   
    ih=im.getHeight(this);   
    pixels=new int[iw*ih];   

    try{   
      PixelGrabber pg=new PixelGrabber(im,0,0,iw,ih,pixels,0,iw);   
      pg.grabPixels();   
    }catch (InterruptedException e3) {   
      e3.printStackTrace();   
    }   

  
    ImageProducer ip=new MemoryImageSource(iw,ih,pixels,0,iw);   
    tmp=createImage(ip);   
    flagLoad=true;   
    repaint();   
  }   

  public void jBlur_ActionPerformed(ActionEvent e)   
  {   
    
	  if(flagLoad){   
      //blur the pic 
	  System.out.println("Client: begin to do FFT and transfer information...");
      newPixels=new double [iw*ih];   

      for(int i=0;i<ih;i++)   
      {   
        for(int j=0;j<iw;j++)   
        {   
          newPixels[i*iw+j]=pixels[i*iw+j]&0x00ffffff;   

        }   
      }   

      //initialize    
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
      
      //System.out.println("complex[512] = "+ complex[512].re()+"+i*"+complex[512].im());
    
      System.out.println("size of data sent to server = iw*ih*2: "+iw*ih*2);
      

      for (int i = 0; i< FFT_res.length/2; ++i) {
        FFT_res[i*2] = complex[i].re();
        FFT_res[i*2+1] = complex[i].im();

      }
     
      //---------------------------------- DATA TRANSFER ----------------------------//
     try{
          //create a new client socket 
          String serverIP = "127.0.0.1";
          System.out.println("Client: try to connect with server...");
          int serverPort = 3600;
          @SuppressWarnings("resource")
          //try to connect to server 
         
          Socket client = new Socket(serverIP, serverPort);
         //send data to server 
          ObjectOutputStream outputStream = new ObjectOutputStream(client.getOutputStream());
          outputStream.writeObject(FFT_res); 
          //recieve msg from server 
          ObjectInputStream ois = new ObjectInputStream(client.getInputStream());
          String serverMessage = (String)ois.readObject(); //reader.readLine();
          System.out.println("Server Message: " + serverMessage);
         }catch (IOException ex) {
              ex.printStackTrace();
        } catch (ClassNotFoundException en) {
          // TODO Auto-generated catch block
              en.printStackTrace();
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

  if(flagLoad & flagBlur){   

    //restore the pic  
    newPixels=new double [iw*ih];     

    //ifft   
    ifft2=new IFFT2();   
    ifft2.setData(iw,ih,complex);   
    newPixels=ifft2.getPixels();   

    //standardize  
    double max=newPixels[0];   
    for(int i=1;i<iw*ih;i++)   
    {   
      if(max<newPixels[i])   
      {   
        max=newPixels[i];   
        System.out.println("ayaaaa   "+i);
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

 //define main method, set the size of window and display
public static void main(String[] args) {   
  Client client = new Client();   
  client.setLocation(50,50);   
  client.setSize(500,400);   
  client.show();   
}    
}  
