package observer;

import java.util.ArrayList;

/**
 * 
 * Observeble class that implements the basic funktions
 * 
 * @author mfrank
 *
 */
public class Observeble {

	private final ArrayList<UIObserver> observerList;

	/**
	 * Constructor that inits the observerlist
	 */
	public Observeble() {
		observerList = new ArrayList<UIObserver>();
	}

	/**
	 * Removes an observer from the list. If the given observer is not found.
	 * Nothing happens.
	 * 
	 * @param observer
	 *            item to remove
	 */
	public void removeObserver(final UIObserver observer) {
		observerList.remove(observer);
	}

	/**
	 * Adds an observer to the observable.
	 * 
	 * @param observer
	 *            should not be null
	 */
	public void addObserver(final UIObserver observer) {
		observerList.add(observer);
	}

	/**
	 * 
	 * invokes the update procedure. All registered observer will be notified
	 * 
	 * @param string
	 *            Update string
	 */
	public void notifyAll(final String string) {
		for (UIObserver aObserver : observerList) {
			aObserver.update(string);
		}
	}

	/**
	 * tells all observer that the current workload is done. This is optional an
	 * not asked in the exercise.
	 */
	public void notifyAllWorkloadDone() {
		for (UIObserver aObserver : observerList) {
			aObserver.workloadDone();
		}
	}
}
