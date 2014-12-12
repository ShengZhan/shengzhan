package server;



//FFT1.java   

import java.awt.*;   

public class FFT1   
{   
	

	 // compute the FFT of x[], assuming its length is a power of 2
  public static Complex[] fft(Complex[] x) {
      int N = x.length;

      // base case
      if (N == 1) return new Complex[] { x[0] };

      // radix 2 Cooley-Tukey FFT
      if (N % 2 != 0) { throw new RuntimeException("N is not a power of 2"); }

      // fft of even terms
      Complex[] even = new Complex[N/2];
      for (int k = 0; k < N/2; k++) {
          even[k] = x[2*k];
      }
      Complex[] q = fft(even);

      // fft of odd terms
      Complex[] odd  = even;  // reuse the array
      for (int k = 0; k < N/2; k++) {
          odd[k] = x[2*k + 1];
      }
      Complex[] r = fft(odd);

      // combine
      Complex[] y = new Complex[N];
      for (int k = 0; k < N/2; k++) {
          double kth = -2 * k * Math.PI / N;
          Complex wk = new Complex(Math.cos(kth), Math.sin(kth));
          y[k]       = q[k].plus(wk.times(r[k]));
          y[k + N/2] = q[k].minus(wk.times(r[k]));
      }
      return y;
  }

/* 
  
 public static void main(String[] args){  
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
   
 FFT1 of=new FFT1();  
   
 for(i=0;i<4;i++)  
 {  
 td[i].set_re(i+1);  
 td[i].set_im(0);  
 }  
   
 fd=fft(td);  
   
 for(i=0;i<4;i++)  
 {  
 System.out.println("the input is "+td[i].re()+"\n");  
   
 }  
   
 for(i=0;i<4;i++)  
 {  
 System.out.println("the answer is "+fd[i].re()+"+"+fd[i].im()+"*i"+"\n");  
 }    
 }  */


}  
