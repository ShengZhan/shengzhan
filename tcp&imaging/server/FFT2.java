package server;


//FFT2.java   


public class FFT2 {   
   
int iw,ih;   
double []pixels;   
Complex []td;   
Complex []fd;   
   
FFT1 fft1;   
   
 
int w = 1;   
int h = 1;   
int wp=0;   
int hp=0;   


public FFT2()   
{   
    System.out.println("FFT2()");   
}   
   

public void setData(int iw,int ih,double []pixels){   
           
        this.iw=iw;   
        this.ih=ih;   
           
        this.pixels=new double[iw*ih];   
        this.pixels=pixels;   
           
    while(w*2<=iw)   
    {   
        w*=2;   
        wp++;   
    }   
    while(h*2<=ih)   
    {   
        h*=2;   
        hp++;   
    }  
    
    td=new Complex[h*w];   
    fd=new Complex[h*w];   
       
    for(int i=0;i<h;i++)   
    {   
        for(int j=0;j<w;j++)   
        {   
            fd[i*w+j]=new Complex();   
            td[i*w+j]=new Complex(pixels[i*w+j],0);   
        }   
    }   
       
    for(int i=0;i<h;i++)   
    {   
        Complex [] tempW1=new Complex[w];   
        Complex [] tempW2=new Complex[w];   
        for(int j=0;j<w;j++)   
        {   
            tempW1[j]=new Complex(0,0);   
            tempW2[j]=new Complex(0,0);   
        }   
           
        for(int j=0;j<w;j++)   
        {   
            tempW1[j]=td[i*w+j];   
        }   
           
        fft1=new FFT1();   
       // fft1.setData(tempW1,wp);   
           
        //tempW2=fft1.getData();   
        tempW2=fft1.fft(tempW1); 
           
        for(int j=0;j<w;j++)   
        {   
            fd[i*w+j]=tempW2[j];   
        }   
    }   
       
    for(int i=0;i<h;i++)   
    {   
        for(int j=0;j<w;j++)   
        {   
            td[j*h+i]=fd[i*w+j];   
        }   
    }   
       
       
    for(int i=0;i<w;i++)   
    {   
        Complex [] tempW1=new Complex[h];   
        Complex [] tempW2=new Complex[h];   
           
        for(int j=0;j<h;j++)   
        {   
            tempW1[j]=new Complex(0,0);                    
            tempW2[j]=new Complex(0,0);   
        }   
           
        for(int j=0;j<h;j++)   
        {   
            tempW1[j]=td[i*h+j];   
        }   
       
       // fft1.setData(tempW1,hp);   
           
        //tempW2=fft1.getData();
        tempW2=fft1.fft(tempW1); 
           
        for(int j=0;j<h;j++)   
        {   
            fd[i*h+j]=tempW2[j];   
        }   
    }   
       
    for(int i=0;i<h;i++)   
    {   
        for(int j=0;j<w;j++)   
        {   
            td[i*w+j]=fd[j*h+i];   
        }   
    }   
}      
       
public Complex [] getComplex(){   
       
    return td;   
   
}   
   
public double []getPixels(){   
       
    for(int i=0;i<h;i++)   
    {   
        for(int j=0;j<w;j++)   
        {   
            double re=td[i*w+j].re();   
            double im=td[i*w+j].im();   
               
            double temp=Math.sqrt(re*re+im*im)/100.0;   
               
            
            pixels[i*w+j]=temp;   
        }   
    }   
    return pixels;   
}   
       
public static void main(String []args)   
{   
    new FFT2();   
}   
   
}  
