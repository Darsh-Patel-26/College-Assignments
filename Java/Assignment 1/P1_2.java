class AddCMl
{
    public static void main(String[] args) 
    {
        if(args.length<2)
        {
            System.out.println("Incomplete Arguments!!");
            return;
        }

        int sub1 = Integer.parseInt(args[0]);
        int sub2 = Integer.parseInt(args[1]);

        int total = sub1 + sub2;
        System.out.println("Total is : "+total);
    }
}