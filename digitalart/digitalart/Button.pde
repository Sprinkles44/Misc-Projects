class Button{
  int x;
  int y;
  int xs;
  int ys;
  
  Button(int x_pos,int y_pos,int x_size,int y_size){
    x=x_pos;
    y=y_pos;
    xs=x_size;
    ys=y_size;
  }
  
  void display(String text){
    String txt=text;
    fill(100,200,150);
    rect(x,y,xs,ys);
    fill(55);
    text(txt,x,y,xs,ys);
  }
  
  void click(){
    // event to be used in void mousePressed() placed here
    if (mouseX >= x && mouseX <= x+xs && mouseY >= y && mouseY <= y+ys){
      mousePressed();
    }
  }
}