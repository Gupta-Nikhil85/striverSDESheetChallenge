void solve(vector<vector<int>> &image, int x, int y, int newColor, int color){
    if(x<0 || y<0 || x>=image.size() || y>=image[0].size() 
       || image[x][y]!=color) return;
    image[x][y]=newColor;
    solve(image, x-1, y, newColor, color);
    solve(image, x+1, y, newColor, color);
    solve(image, x, y-1, newColor, color);
    solve(image, x, y+1, newColor, color);
    return;
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    if(newColor==image[x][y]) return image;
    solve(image, x, y, newColor, image[x][y]);
    return image;
}