var path;
var m1=[];
var m2=[];
var bias=[];
var error=[];
var nb=1;
var sizeR;
var index;
var z =100;
var k;
var ep;
var complete = false;
var fs;
var er;
var c;
var etouou;
function setup(){
  createCanvas(801,400);
  sizeR=20;
  let url_string = window.location.href;
  let url = new URL(url_string);
  path = url.searchParams.get("path");
  console.log(path);
loadStrings(path, doText);
ep = select('#epoch');
fs = select('#fs');
er = select('#error');

}
function f(m1,x1,m2,x2,b){
  return (m1*x1 + m2*x2 + b);
}
function act(sum,k){
  return (1/(1+exp(-k*sum)));
}
function draw(){
  //background(255);
  ep.html(frameCount%10000);
  index = (frameCount -1) % (nb-1);
for(var i=0;i<400;i+=sizeR){
  for(var j=0;j<400;j+=sizeR){
    strokeWeight(1);
    stroke(0);
    c = 255- (act(f(m1[index],i/400,m2[index],(1-(j/400)),bias[index]),k) * 255);
    fill(c,255-c,0);
    rect(i,j,sizeR,sizeR);
  }
}
strokeWeight(3);
stroke(0);
er.html(error[frameCount%10000]);
point(401+(((frameCount%10000)/10000)*400),300-(error[frameCount%10000]*401));
}

function doText(data) {
  etouou = data[0];
  k = data[1];
  for (var i=2; i<data.length; i+=4) {
  error[(i-2)/4]=parseFloat(data[i+0]);
  m1[(i-2)/4]=parseFloat(data[i+1]);
  m2[(i-2)/4]=parseFloat(data[i+2]);
  bias[(i-2)/4]=parseFloat(data[i+3]);
  nb++;
  }
fs.html(etouou+" - Done");
complete = true;
}
