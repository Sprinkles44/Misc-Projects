class bgFade {   // Class used to fade the background colors back and forth.
  int k;
  
  bgFade() {
  k=0;
  }
  
  void display(){
    k = k %200;
    int smooth= 200;
    float r = 100*cos(2*PI*k/smooth)+127.5;
    //float g = 100*sin(degrees(k)/smooth)+127.5;
    //float b = 110*cos(degrees(k)/smooth)+127.5;
    //background(r,15,b);
    background(r);
    k++;
  }
}