package main;

import Listener.GUIListener;
import Listener.TerminalListener;

/**
 * 
 * Main method that starts the program
 * 
 * Please note that this is only an example code. There is no claim that it is
 * completed or out of errors!
 * 
 * @author mfrank
 * @version 0.8
 *
 */
public class Main {

	public static void main(String[] args) {
		new TerminalListener();
		new GUIListener();

	}

}
