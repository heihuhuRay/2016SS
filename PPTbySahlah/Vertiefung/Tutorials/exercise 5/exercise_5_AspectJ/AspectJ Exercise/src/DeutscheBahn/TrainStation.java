package DeutscheBahn;

import java.awt.Point;

/**
 * 
 * Train Station that has a name and a location
 * 
 * @author mfrank
 *
 */
public class TrainStation {

	private final String name; 
	private final Point location;
	
	public TrainStation(final String name, final Point location) {
		this.name = name;
		this.location = location;
	}

	/**
	 * @return location of the station
	 */
	public Point getLocation() {
		return location;
	}

	/**
	 * @return name of the station
	 */
	public String getName() {
		// TODO Auto-generated method stub
		return this.name;
	}

}
