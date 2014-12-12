package Client;
//package finalproject3;

//IFFT2.java   

public class IFFT2 {   
   
int iw,ih;   
double []pixels;   
Complex [] td;   
Complex [] fd;   
   
IFFT1 ifft1;   
   
int w = 1;   
int h = 1;   
int wp=0;   
int hp=0;   
   
public IFFT2()   
{   
    System.out.println("IFFT2()");   
}   
   
public void setData(int iw,int ih,Complex []complex){   
           
    this.iw=iw;   
    this.ih=ih;   
       
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
            fd[i*w+j]=new Complex(complex[i*w+j].re(),complex[i*w+j].im());   
            td[i*w+j]=new Complex();   
        }   
    }   
       
    for(int i=0;i<h;i++)   
    {   
        for(int j=0;j<w;j++)   
        {   
            td[i*w+j]=fd[j*h+i];   
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
            
        ifft1=new IFFT1();   
        ifft1.setData(tempW1,hp);   
           
        tempW2=ifft1.getData();   
           
        for(int j=0;j<h;j++)   
        {   
            fd[i*h+j]=tempW2[j];   
        }   
    }   
       
       
    for(int i=0;i<h;i++)   
    {   
        for(int j=0;j<w;j++)   
        {   
            td[j*h+i]=fd[i*w+j];   
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
           
        ifft1=new IFFT1();   
        ifft1.setData(tempW1,wp);   
           
        tempW2=ifft1.getData();   
           
        for(int j=0;j<w;j++)   
        {   
            fd[i*w+j]=tempW2[j];   
        }   
    }   
       
}   
       
//   
public Complex[] getComplex(){   
    return td;   
}   
   
public double [] getPixels(){   
       
    pixels=new double[iw*ih];   
    for(int i=0;i<h;i++)   
    {   
        for(int j=0;j<w;j++)   
        {   
            double re=fd[i*w+j].re();   
            double im=fd[i*w+j].im();   
               
            double temp=Math.sqrt(re*re+im*im);    
               
            pixels[i*w+j]=temp;   
        }   
    }   
return pixels;   
   
}   
       
public static void main(String []args)   
{   
    new IFFT2();   
}   
   
}  
