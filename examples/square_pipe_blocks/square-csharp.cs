/*
 * On Linux, compile with:
 *  gmcs square-csharp.cs
 * or
 *  mcs square-csharp.cs
 * Run with:
 *  mono square-csharp.exe
 * or,
 *  wine square-csharp.exe
 */
using System;
using System.IO;

public class SquareCSharp
{
    static public void Main ()
    {
        Stream inputStream = Console.OpenStandardInput();
        Stream outputStream = Console.OpenStandardOutput();
        byte[] bytes = new byte[ sizeof(float) ];

        while (true) {

            int outputLength = inputStream.Read(bytes, 0, sizeof(float) );
            if (outputLength == 0)
                break ;
            if (outputLength != sizeof (float)) {
                Console.Error.WriteLine("Error: can't read a float");
                Environment.Exit(1);
            }

            float val = BitConverter.ToSingle(bytes, 0);

            // Console.Error.WriteLine(val);

            val *= val;

            byte[] outBytes = BitConverter.GetBytes(val);
            outputStream.Write(outBytes, 0, sizeof(float));
        }
    }
}
