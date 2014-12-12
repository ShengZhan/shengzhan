package server;


//IFFT1.java   


public class IFFT1 {   
   
int count;   
int power;   
   
Complex[] x;   
Complex[] fd;   
   
FFT1 fft1;   
   
public IFFT1(){   
       
    //System.out.println("IFFT1.java");   
}   
   
   
public void setData(Complex [] data,int power){   
   
    this.power=power;   
               
    count=1<<power;      
       
    x=new Complex[count];   
        fd=new Complex[count];   
           
        for(int i=0;i<count;i++)   
        {   
            x[i]=new Complex();   
            fd[i]=new Complex();   
        }   
           
        for(int i=0;i<count;i++)   
        {   
            x[i]=data[i];   
               
        }   
}   
   
public Complex [] getData(){   
   
for(int i=0;i<count;i++)   
{   
    double im=-x[i].im();   
    x[i].set_im(im);   
}   
   
fft1=new FFT1();   
// fft1.setData(x,power);   
//fd=fft1.getData();  
fd = fft1.fft(x);
   
for(int i=0;i<count;i++)   
{   
    double re=fd[i].re();   
    double im=-fd[i].im();   
    fd[i].set_im(im/count);   
    fd[i].set_re(re/count);   
}   
   
    return fd;   
}   


/*public static void main(String[] args){  
    Complex [] td;  
    Complex [] fd;  
      
    int i=0;  
    td=new Complex[4];  
    fd=new Complex[4];  
      
    for(i=0;i<4;i++)  
    {  
        td[i]=new Complex();  
        fd[i]=new Complex();  
    }  
      
    IFFT1 ifft1=new IFFT1();  
      
    td[0].set_re(10);
    td[0].set_im(0);
    
      
    td[1].set_re(-2);  
    td[1].set_im(2);  
      
    td[2].set_re(-2);  
    td[2].set_im(0);  
      
    td[3].set_re(-2);  
    td[3].set_im(-2);  
  
    ifft1.setData(td,2);  
    fd=ifft1.getData();  
      
    for(i=0;i<4;i++)  
    {  
  	   System.out.println("the input is "+td[i].re()+"+"+td[i].im()+"*i"+"\n"); 
              
    }  
      
    for(i=0;i<4;i++)  
    {  
  	   System.out.println("the answer is "+fd[i].re()+"+"+fd[i].im()+"*i"+"\n");  
    }     
}  
*/
       
} 
