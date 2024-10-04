public class Main
{
    public static int ways(int s1,int s2,int r,int c,int[][] isVisited)
    {
        if(s1<0 || s2< 0) return 0;
        if(s1>r || s2 > c ) return 0;
        if(isVisited[s1][s2] == 1) return 0;
        if(s1==r && s2==c)
        {
            return 1;
        }
        
        isVisited[s1][s2] = 1;
        int right = ways(s1,s2+1,r,c,isVisited);
        int bottom = ways(s1+1,s2,r,c,isVisited);
        int left = ways(s1,s2-1,r,c,isVisited);
        int top =ways(s1-1,s2,r,c,isVisited);
        
        isVisited[s1][s2] = 0;
        return right+bottom+left+top;
    }
    public static void path(int s1,int s2,int r,int c,String s,int[][] isVisited)
    {
        if(s1<0 || s2< 0) return ;
        if(s1>r || s2 > c ) return;
         if(isVisited[s1][s2] == 1) return ;
        if(s1==r && s2==c)
        {
            System.out.println(s);
            return;
        }
         isVisited[s1][s2] = 1;
        path(s1,s2+1,r,c,s+'R',isVisited);
        path(s1+1,s2,r,c,s+'D',isVisited);
        path(s1,s2-1,r,c,s+'L',isVisited);
        path(s1-1,s2,r,c,s+'T',isVisited);
        
         isVisited[s1][s2] = 0;
    }
	public static void main(String[] args) {
	   int r = 3;
	   int c = 3;
	   
	   int[][] isVisited = new int[r][c];
	   System.out.println(ways(0,0,r-1,c-1,isVisited));
	   
	   path(0,0,r-1,c-1,"",isVisited);
	}
}
