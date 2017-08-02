package DeutscheBahn;

import java.awt.Point;

import interfaces.DriveableTrain;

/**
 * 
 * Simple example implementation of a train. 
 * 
 * @author mfrank
 *
 */
public class Train implements DriveableTrain{
	
	private final String name;
	private Point location;
	private TrainStation destination;
	
	// Constructor
	public Train(final String name, final Point location) {
		this.location = location;
		this.name = name;
	}

	@Override
	public void setDestionation(TrainStation station) {
		System.out.println("set Destination to:"+ station.getName());
		this.destination = station;
	}

	@Override
	public void setLocation(Point currentLocation) {
		this.location = currentLocation;
	}

	@Override
	public double getDistanceToDestination() {
		return location.distance(destination.getLocation());
	}

	@Override
	public void driveToDestination() {
		location = destination.getLocation();
	}

}
