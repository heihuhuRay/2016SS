package Listener;

import java.text.SimpleDateFormat;
import java.util.Date;

import observer.UIObserver;
import storytelling.Storyteller;

/**
 * 
 * Observer interface that defines to methods for the notification process
 * (second method is optional)
 * 
 * @author mfrank
 *
 */
public class TerminalListener implements UIObserver {

	private final SimpleDateFormat df;

	/**
	 * Contructor. Main task: register itself to the observable
	 */
	public TerminalListener() {
		df = new SimpleDateFormat("hh:MM:ss");

		Storyteller.getStoryteller().addObserver(this);
	}

	@Override
	public void update(String story) {
		System.out.println(df.format(new Date(System.currentTimeMillis())) + ": " + story);

	}

	@Override
	public void workloadDone() {
		System.out.println("Done telling all storys");
	}

}
