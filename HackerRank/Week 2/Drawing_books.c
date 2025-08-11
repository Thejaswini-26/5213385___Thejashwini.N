//DRawing books C program
int pageCount(int n, int p) {
    int front=p/2;
    int back=(n/2)-(p/2);
    if(front<back){
        return front;
    }
    else {
    return back;
    }

}
