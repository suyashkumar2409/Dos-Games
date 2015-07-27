package connect4;
import java.util.Scanner;
public class Connect4 {
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        String pone,ptwo;
        System.out.println("Enter the names of two players one by one");
        pone=input.nextLine();
        ptwo=input.nextLine();
         System.out.println(pone+ " ,Heads or tails??(h/t)");
        String choice,random;
        choice=input.next();
        while(!("h".equals(choice)||"t".equals(choice)||"H".equals(choice)||"T".equals(choice)))
        {
            System.out.println("Type either 'h' or 't' ");
            choice=input.next();
        }
        random=""+(int)(Math.floor(Math.random()*2));
        System.out.println(random);
        if("1".equals(random))
            random="h";
        else 
            random="t";
        
        if("h".equals(random))
            System.out.println("It is Heads!!");
        else
            System.out.println("It is Tails!!");
        
        choice=choice.toLowerCase();
        
        if(choice.equals(random))
        {
            
            System.out.println(pone+" wins toss, will start first");
        }
        else
        {
            System.out.println(ptwo+" wins toss, will start first");
            String temp;
            temp=pone;
            pone=ptwo;
            ptwo=temp;
        }
        int[][] game=new int[7][6];
        print(game);
        do{
            Scanner newinput=new Scanner(System.in);
            
            System.out.println(pone+", enter which column you want to throw your red peg into");
            choice=newinput.nextLine();
            //updateArray(choice,game,1);
            while(updateArray(choice,game,1))
            {
                System.out.println(pone+", enter which column you want to throw your red peg into");
                choice=input.nextLine();
            }
            print(game);
            int gameOver=checkGame(game);
            if(gameOver==1||gameOver==2)
            {
                if(gameOver==1)
                    System.out.println(pone+ " won!!!!");
                if(gameOver==2)
                    System.out.println(ptwo+ " won!!!!");
                break;
            }
            System.out.println(ptwo+" ,enter which column you want to throw your yellow peg into");
            choice=newinput.nextLine();
            //updateArray(choice,game,2);
            while(updateArray(choice,game,2))
            {
               
                System.out.println(pone+" ,enter which column you want to throw your yellow peg into");
                choice=input.nextLine();
            }
            print(game);
            gameOver=checkGame(game);
            if(gameOver==1||gameOver==2)
            {
                if(gameOver==1)
                    System.out.println(pone+ " won!!!!");
                if(gameOver==2)
                    System.out.println(ptwo+ " won!!!!");
                break;
            }
            
    }while(true)
                ;
    }
    
    
    
    public static int checkGame(int[][] game)
    {
        boolean isThere=false;
        for(int i=0;i<7;i++)
        {
            for(int j=0;j<6;j++)
            {
                if(game[i][j]!=0)           //if not 0
                {
                    if(check(game,i,j))     //if winning
                    {
                        return game[i][j];
                    }
                }
                else
                    if(!isThere)
                        isThere=true;
            }
        }
        if(isThere)
            return 0;
        else
            return 3;               //Draw
    }
    
    
    public static boolean check(int[][]game,int y,int x)
    {
        int check=game[y][x],connect=0;
        if(x>=0&&x<=2)                         //checking horizontally
        {
            
            for(int i=y,j=x;j<x+4;j++)
            {
                if(game[i][j]==check)
                    connect++;
            }
            if(connect==4)
                return true;
            else
                connect=0;
        }
        if(y>=0&&y<=3)                         //checking vertically
        {
            for(int i=y,j=x;i<y+4;i++)
            {
                if(game[i][j]==check)
                    connect++;
            }
            if(connect==4)
                return true;
            else
                connect=0;
        }
        if(x>=0&&x<=2&&y>=4&&y<=6)                     //checking cross up
        {
            for(int i=y,j=x;j<x+4;j++,i--)
                {
                if(game[i][j]==check)
                    connect++;
            }
            if(connect==4)
                return true;
            else
                connect=0;
        }
        if(x>=0&&x<=2&&y>=0&&y<=3)                     //checking cross down
        {
            for(int i=y,j=x;j<x+4;j++,i++)
                {
                if(game[i][j]==check)
                    connect++;
            }
            if(connect==4)
                return true;
            else
                connect=0;
        }
        return false;
    }
    public static boolean updateArray(String choice,int[][] game,int a)
    {
        int temp=Integer.parseInt(choice)-1;
        if(temp<0||temp>5)
        {
            System.out.println("Enter a number between 1-6!!!");
        }
        for(int i=6;i>=0;i--)
        {
            if(game[i][temp]==0)
            {
                game[i][temp]=a;
               
                return false;
            }
        }
        System.out.println("That column, is already full!!");
        return true;
    }
    
    
    
    public static String returnColour(int a)
    {
        if(a==0)
            return " ";
        else if(a==1)
            return "R";
        else
            return "Y";
    }
    
    
    
    public static void print(int[][] game)
    {
        System.out.print("|");
        for(int i=0;i<6;i++)
        {
            System.out.print(i+1);
            if(i==5)
                    System.out.println("|");
                else
                    System.out.print("|");    
        }
        for(int i=0;i<7;i++)       //this sequences by rows
        {
            
            System.out.print("|");
            for(int j=0;j<6;j++)
            {
                
                System.out.print(returnColour(game[i][j]));
                if(j==5)
                    System.out.println("|");
                else
                    System.out.print("|");
            }
            
        }
    }
    
    
    }
    
    
    

