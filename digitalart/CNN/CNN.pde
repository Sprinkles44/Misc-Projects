// Network demo No.1
// by t.takaishi
// (inspired by HTTPClient.pde)

import processing.net.*;

Client c;
String data;
String[][] m;
String host="rss.cnn.com"; 
String rss="/rss/edition.rdf"; // English!!

void setup()
{
  size(1200,200);
  background(0);
  fill(255);
  c = new Client(this, host,80);
  c.write("GET "+rss+" HTTP/1.1\n"); // RSS feeds are usually in XML
  c.write("host: "+host+"\n"); 
  c.write("Connection: Close\n"); 
  c.write("\n");
}

void draw()
{
  if(c.available() > 0)
  {
    data = c.readString();
    println(data);
    m=matchAll(data,"<title>(.*?)</title>");
  }
  if(m!=null){
    background(0);
    textSize(20);
    text(m[int(random(m.length))][1],5,100);
    myDelay(7000);
  }
}

void myDelay(int ms)
{
  try{
    Thread.sleep(ms);
  }
  catch(Exception e){}
}