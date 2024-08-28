namespace testerr
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] x = { 5, 4, 3, 2, 1 };
            //1,4,3,2,5
            //1,5,3,2,4
            //


            for(int i = 0; i < x.Length / 2; i++)
            {
                int temp = x[i];
                x[i] = x[i + 1];
            }

            Console.WriteLine(x.ToString());
        }
    }
}