Filesuccesseur allocSFS(int n, int p){
  Filesuccesseur fs;
  fs.nbsom=n;
  fs.nbarcs=p;
  fs.FS=allocTab[p];
  fs.APS=allocTab(n+1);
  return fs;
}
