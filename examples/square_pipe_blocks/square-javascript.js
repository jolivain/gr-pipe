/*
 * This is not pure JavaScript, because I'm not aware of any standard I/O functions.
 * Instead, I'm using Rhino (tested with version 1.7R3) http://www.mozilla.org/rhino/
 *
 * This code is inspired from the Java version.
 * 
 * With with:
 *  rhino square-javascript.js
 */

var dIn  = java.io.DataInputStream( java.lang.System.in );
var dOut = java.io.DataOutputStream( java.lang.System.out );
var buf = java.lang.reflect.Array.newInstance(java.lang.Byte.TYPE, 4)

var val = 0;
var iVal = 0;

while (true) {
    try {
	if (java.nio.ByteOrder.nativeOrder() == java.nio.ByteOrder.LITTLE_ENDIAN) {
	    dIn.readFully(buf, 0, 4);
	    iVal =  (buf[3]) << 24 | (buf[2] & 0xFF) << 16 | (buf[1] & 0xFF) <<  8 | (buf[0] & 0xFF);
	    val = java.lang.Float.intBitsToFloat(iVal);
	}
	else {
	    val = dIn.readFloat();
	}

        // java.lang.System.err.println(val);

	val *= val;

	if (java.nio.ByteOrder.nativeOrder() == java.nio.ByteOrder.LITTLE_ENDIAN) {
	    iVal = java.lang.Float.floatToIntBits(val);
	    iVal = (((iVal << 24) & 0xFF000000) + ((iVal << 8) & 0x00FF0000) + ((iVal >> 8) & 0x0000FF00) + ((iVal >> 24) & 0x000000FF));
	    dOut.writeInt(iVal);
	}
	else {
	    dOut.writeFloat(val);
	}

    } catch (e if e instanceof JavaException && e == "JavaException: java.io.EOFException: null") {
	break ;
    } catch (e) {
        java.lang.System.err.println(e);
        java.lang.System.exit(1);
    }
}
