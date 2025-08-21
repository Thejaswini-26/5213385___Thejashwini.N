char** copyGrid(int rows, int cols, char** grid){
char** newgrid=malloc(rows*sizeof(char*));
    for(int i=0;i<rows;i++){
        newgrid[i]=malloc((cols+1)*sizeof(char));
        strcpy(newgrid[i],grid[i]);
    }
    return newgrid;
   }
     
 void explode(int rows, int cols, char** grid,  char** bombs){
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++){
            if(bombs[i][j] == 'O'){
                grid[i][j]='.';
                if(i>0)grid[i-1][j]='.';
                if(i<rows-1)grid[i+1][j]='.';
                if(j>0)grid[i][j-1]='.';
                if(j<cols-1)grid[i][j+1]='.';
            }
        }
 }  
   
char** bomberMan(int n, int grid_count, char** grid, int* result_count) {
   int rows=grid_count;
   int cols=strlen(grid[0]);
   *result_count=rows;
   
  
  if(n==1){
    return copyGrid(rows,cols,grid);
  }
   
   if(n%2==0){
    char** full = malloc(rows *sizeof(char*));
    for(int i=0;i<rows;i++){
        full[i]=malloc((cols +1)*sizeof(char));
        memset(full[i],'O',cols);
        full[i][cols]='\0';
    }
    return full;
   }
   
   
   char** first = copyGrid(rows, cols, grid);
   char** afterfirst = copyGrid(rows, cols, first);
   for(int i=0;i<rows;i++){
    memset(afterfirst[i],'O',cols);
   }
   explode(rows,cols,afterfirst,first);
   
   
   if(n%4==3){
    for(int i=0;i<rows;i++) free(first[i]);
    free(first);
    return afterfirst;
   }
   
   
    char** second=copyGrid(rows, cols, afterfirst);
    char** aftersecond=copyGrid(rows, cols, second);
    for(int i=0;i<rows;i++){
        memset(aftersecond[i],'O',cols);
    }
    explode(rows,cols,aftersecond,second);
    
    for(int i=0;i<rows;i++){
        free(first[i]);
        free(afterfirst[i]);
        free(second[i]);
    }
    free(first);
    free(afterfirst);
    free(second);
    return aftersecond; 
    
}