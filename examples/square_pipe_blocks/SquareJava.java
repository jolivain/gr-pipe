/*
 * Compile with:
 *   javac SquareJava.java
 * Run with:
 *   java SquareJava
 */

import java.io.*;
import java.nio.ByteOrder;

class SquareJava {

    public static void main(String args[]) {
	DataInputStream  dIn  = new DataInputStream(System.in);
	DataOutputStream dOut = new DataOutputStream(System.out);
	byte buf[] = new byte[4];

	while (true) {
	    try {
		int iVal;
		float val;
		if (ByteOrder.nativeOrder() == ByteOrder.LITTLE_ENDIAN) {
		    dIn.readFully(buf, 0, 4);
		    iVal =  (buf[3]) << 24 | (buf[2]&0xff) << 16 | (buf[1]&0xff) <<  8 | (buf[0]&0xff);
		    val = Float.intBitsToFloat(iVal);
		}
		else {
		    val = dIn.readFloat();
		}

		//System.err.println(val);
		val *= val;

		if (ByteOrder.nativeOrder() == ByteOrder.LITTLE_ENDIAN) {
		    iVal = Float.floatToIntBits(val);
		    iVal = ((iVal<<24)+((iVal<<8)&0x00FF0000)+((iVal>>8)&0x0000FF00)+(iVal>>24));
		    dOut.writeInt(iVal);
		}
		else {
		    dOut.writeFloat(val);
		}

	    } catch (EOFException e) {
		break ;
	    } catch (Exception e) {
		System.err.println(e);
		System.exit(1);
	    }
	}

	System.exit(0);
    }
}
