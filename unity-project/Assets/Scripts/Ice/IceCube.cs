using UnityEngine;
using System;
using demo;

public class IceCube : MonoBehaviour {

	// Use this for initialization
	void Start () {
        Ice.Communicator ic = null;
        try
        {
            ic = Ice.Util.initialize();
            Ice.ObjectPrx obj = ic.stringToProxy("SimplePrinter:default -p 10000");
            
            PrinterPrx printer = PrinterPrxHelper.checkedCast(obj);
            if (printer == null)
                throw new ApplicationException("Invalid proxy");

            printer.printString("Hello World from Unity & ZeroC Ice!");
        }
        catch (Exception e)
        {
            print(e);
        }
        if (ic != null)
        {
            // Clean up
            //
            try
            {
                ic.destroy();
            }
            catch (Exception e)
            {
                print(e);
            }
        }
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
