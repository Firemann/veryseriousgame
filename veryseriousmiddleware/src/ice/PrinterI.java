package ice;

import Ice.Current;
import demo._PrinterDisp;

@SuppressWarnings("serial")
public class PrinterI extends _PrinterDisp {

	@Override
	public void printString(String s, Current __current) {
		System.out.println(s);
	}

}
