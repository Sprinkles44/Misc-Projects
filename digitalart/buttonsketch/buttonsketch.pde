String btxt;
int bx,by,bxs,bys;
Button butt;

void setup(){
  size(640,640);
  bx= width/2;
  by= height/2;
  bxs=100;
  bys=70;
  butt= new Button(bx,by,bxs,bys);
  btxt= "Press me";
}

void draw(){
  butt.display(btxt);
}

void mousePressed(){
  butt.click();
}