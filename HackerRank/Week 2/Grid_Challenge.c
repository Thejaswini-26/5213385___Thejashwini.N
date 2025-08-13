char* gridChallenge(int grid_count, char** grid) {
int len = strlen(grid[0]);

for(int i=0;i<grid_count;i++){
    for(int j=1;j<len;j++){
        char key_letter = grid[i][j];
        int k=j-1;
        while(k>=0&&grid[i][k]>key_letter){
            grid[i][k+1]=grid[i][k];
            k--;
        }
        grid[i][k+1]=key_letter;
    }
}
for(int column=0;column<len;column++){
    for(int row=0;row<grid_count-1;row++){
        if(grid[row][column]>grid[row+1][column]){
            return "NO";
        }
    }
}
return "YES";
}