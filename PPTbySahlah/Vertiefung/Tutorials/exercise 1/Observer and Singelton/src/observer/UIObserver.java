package observer;

/**
 * 
 * Observer interface that definies to methods for the notification process
 * (second method is optional)
 * 
 * @author mfrank
 *
 */
public interface UIObserver{

	/**
	 * Handels the new event. In this case a string is parsed 
	 * 
	 * @param story Update string, should not be null!
	 */
	public void update(String story);

	/**
	 * tells the Observer that the workload is done and can handels end actions
	 */
	public void workloadDone();
	
}
