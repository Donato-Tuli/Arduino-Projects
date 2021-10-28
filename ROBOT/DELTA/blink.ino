void lamp(){
  for(int i=0;i<3;i++){
  digitalWrite(cicalino,1);
  digitalWrite(led,1);
  delay(500);
  digitalWrite(cicalino,0);
  digitalWrite(led,0);
  delay(500);
  }
}

