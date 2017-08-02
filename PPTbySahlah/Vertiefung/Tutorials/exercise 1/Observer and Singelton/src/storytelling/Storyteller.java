package storytelling;

import observer.Observeble;

/**
 * 
 * concrete implementation of the Storryteller that implements the observeble.
 * 
 * @author mfrank
 *
 */
public class Storyteller extends Observeble {

	private static Storyteller STORYTELLER;

	/**
	 * Constructor that calls the parent construtor. DONE.
	 */
	private Storyteller() {
		super();
	}

	/**
	 * Implementation of the singelton pattern. Alternative a Enum can be used.
	 * 
	 * @return the one and only story teller
	 */
	public static Storyteller getStoryteller() {
		if (STORYTELLER == null) {
			synchronized (Storyteller.class) {
				STORYTELLER = new Storyteller();
			}
		}
		return STORYTELLER;
	}

	/**
	 * 
	 * Methode that starts the telling process.
	 * 
	 * This should illustrate one aspect of using the observer. You can decouple
	 * the UI from the rest and each time ther is an update, the UI will be
	 * notified
	 * 
	 * @param numberOfStorys that should be told
	 */
	public void startTelling(final int numberOfStorys) {
		for (int i = 0; i < numberOfStorys; i++) {
			notifyAll("I'm telling story " + i);
			try {
				Thread.sleep((int) (Math.random() * 4000));
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		notifyAllWorkloadDone();
	}
}
