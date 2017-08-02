package interfaces;

import java.awt.Point;

import DeutscheBahn.TrainStation;

/**
 * Interface that defines the function of a train.
 * 
 * @author mfrank
 *
 */
public interface DriveableTrain {

	/**
	 * Sets trains destination
	 * @param station only trainstations 
	 */
	public void setDestionation(final TrainStation station);

	/**
	 * Current location of the train.
	 * @param currentLocation the new location
	 */
	public void setLocation(final Point currentLocation);
	
	/**
	 * @return the distance to the destination
	 */
	public double getDistanceToDestination();
	
	/**
	 * drives to destination
	 */
	public void driveToDestination();
	
}
