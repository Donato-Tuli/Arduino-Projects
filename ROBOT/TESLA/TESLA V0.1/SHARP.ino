
void SHARP(){
x=analogRead(A9);
DistFront=constrain(x,80,530);
   float ff=(1/(0.000413153*DistFront-0.0055266887));
   float gg=(1/(0.000413153*DistFront-0.0055266887));
   float hh=(1/(0.000413153*DistFront-0.0055266887));
   float ll=(1/(0.000413153*DistFront-0.0055266887));
   float dd=(1/(0.000413153*DistFront-0.0055266887));
   float tt=(1/(0.000413153*DistFront-0.0055266887));
   float ww=(1/(0.000413153*DistFront-0.0055266887));
   float fff=(1/(0.000413153*DistFront-0.0055266887));
   float qq=(1/(0.000413153*DistFront-0.0055266887));
   float nn=(1/(0.000413153*DistFront-0.0055266887));
   float ffJ=(1/(0.000413153*DistFront-0.0055266887));
   float ggJ=(1/(0.000413153*DistFront-0.0055266887));
   float hhJ=(1/(0.000413153*DistFront-0.0055266887));
   float llJ=(1/(0.000413153*DistFront-0.0055266887));
   float ddJ=(1/(0.000413153*DistFront-0.0055266887));
   SHARPFRONTALE=(ff+gg+hh+ll+dd+tt+ww+fff+qq+nn+ffJ+ggJ+hhJ+llJ+ddJ)/15;
   
y=analogRead(A8);
DistLate1=constrain(y,80,530);
   float hhh=(1/(0.000413153*DistLate1-0.0055266887));
   float www=(1/(0.000413153*DistLate1-0.0055266887));
   float ttt=(1/(0.000413153*DistLate1-0.0055266887));
   float lll=(1/(0.000413153*DistLate1-0.0055266887));
   float qqqqq=(1/(0.000413153*DistLate1-0.0055266887));
   float mm=(1/(0.000413153*DistLate1-0.0055266887));
   float zzz=(1/(0.000413153*DistLate1-0.0055266887));
   float ee=(1/(0.000413153*DistLate1-0.0055266887));
   float vv=(1/(0.000413153*DistLate1-0.0055266887));
   float xx=(1/(0.000413153*DistLate1-0.0055266887));
   float hhhL=(1/(0.000413153*DistLate1-0.0055266887));
   float wwwL=(1/(0.000413153*DistLate1-0.0055266887));
   float tttL=(1/(0.000413153*DistLate1-0.0055266887));
   float lllL=(1/(0.000413153*DistLate1-0.0055266887));
   float qqqqqL=(1/(0.000413153*DistLate1-0.0055266887));
   SHARPLATERALE1=(hhh+www+ttt+lll+qqqqq+mm+zzz+ee+vv+xx+hhhL+wwwL+tttL+lllL+qqqqqL)/15;

z=analogRead(A10);
DistLate2=constrain(z,80,530);
   float abc=(1/(0.000413153*DistLate2-0.0055266887));
   float bcd=(1/(0.000413153*DistLate2-0.0055266887));
   float def=(1/(0.000413153*DistLate2-0.0055266887));
   float efg=(1/(0.000413153*DistLate2-0.0055266887));
   float fgh=(1/(0.000413153*DistLate2-0.0055266887));
   float ghi=(1/(0.000413153*DistLate2-0.0055266887));
   float hil=(1/(0.000413153*DistLate2-0.0055266887));
   float ilm=(1/(0.000413153*DistLate2-0.0055266887));
   float lmn=(1/(0.000413153*DistLate2-0.0055266887));
   float mno=(1/(0.000413153*DistLate2-0.0055266887));
   float nop=(1/(0.000413153*DistLate2-0.0055266887));
   float opq=(1/(0.000413153*DistLate2-0.0055266887));
   float pqr=(1/(0.000413153*DistLate2-0.0055266887));
   float qrs=(1/(0.000413153*DistLate2-0.0055266887));
   float rsu=(1/(0.000413153*DistLate2-0.0055266887));
   SHARPLATERALE2=(abc+bcd+def+efg+fgh+ghi+hil+ilm+lmn+mno+nop+opq+pqr+qrs+rsu)/15;

 /*l=analogRead(A4);              //SHARP A LUNGA DISTANZA
 DistLunga=constrain(l,103,511);
 lunga=9462/(DistLunga-16.92);*/

}
 
 
