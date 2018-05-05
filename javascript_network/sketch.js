var net;
var path = "uploads/a.nn";
var info;
var arch=[];
var k;
var mu;
var data;
var index=0;
var et;
var found1=found2=found3=false;
var stop = false;
var t1=t2=t3=0;
function preload(){
  info = loadStrings(path);

}
function setup(){
  for(var i =1;i<=parseFloat(info[0]);i++){
    arch.push(parseFloat(info[i]));

  }
  k=parseFloat(info[parseFloat(info[0])+1]);
  mu=parseFloat(info[parseFloat(info[0])+2]);
  info.splice(0,parseFloat(info[0])+3);
  while(index<info.length && stop==false){
    if(found1&&found2&&found3){
      stop=true;
    }
    if(info[index]=="fin1"){
      found1=true;
    }
    if(info[index]=="fin2"){
      found2=true;
    }
    if(info[index]=="fin3"){
      found3=true;
    }
    if(!found1)t1++
    if(found1 && !found2)t2++;
    if(found1 && found2 && !found3)t3++;
    index++;
  }
  t1--;t2--;t3--;
  createCanvas(windowWidth,windowHeight);
  net = new network(100,500,arch);
  data = cuttab(info,t2+t3+3,t1);
  data2 = extrTab(info,"fin1",t2,t1+t3+3);
  data3 = extrTab(info,"fin2",t3,t1+t2+3);
}

function draw(){
  frameRate(20);
  et = floor(frameCount%200/2);
  background(50);
  textSize(25);
  text(et +" %",100,50);
  net.show(data[et],data2[et],data3[et]);

}

function cuttab(tab,deb,taille){
  var nbr = floor(tab.length/(taille+deb));
  var res =new Array(nbr-1);
  for(var i=0;i<nbr-1;i++){
    res[i]=new Array(taille);
    if(i==0){
      for (var j=(i*taille);j<=(i+1)*taille;j++){
        res[i][j-((i*taille))]=tab[j];
      }
    }else{
      var d =(i*(deb+taille+1));
      var f = d+taille;
      for (var j=d;j<=f;j++){
        res[i][j-d]=tab[j];
      }
    }
  }
  return res;
}
function extrTab(tab,word,t1,t2){
  var nbr = floor(tab.length/(t1+t2));
  var res =new Array(nbr-1);
  var read = false;
  for(var i=0;i<nbr-1;i++){
    res[i] = new Array(t1);
  }
  var index=0;
  var cpt = 0;
  for(var i=0;i<tab.length;i++){
    if(read && cpt<t1){
      res[index][cpt]= tab[i];
      cpt++;
    }
    if(cpt==t1){
      cpt=0;
      read=false;
      index++;
    }
    if(tab[i]==word)read = true;
  }
  return res;
}
