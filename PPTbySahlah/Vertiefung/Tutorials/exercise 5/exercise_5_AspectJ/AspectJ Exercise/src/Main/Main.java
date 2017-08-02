package Main;

import java.awt.Point;

import org.omg.IOP.TAG_INTERNET_IOP;

import DeutscheBahn.Train;
import DeutscheBahn.TrainStation;

/**
 * 
 * Example for one possible solution for exercise 5. 
 * 
 * Only implmenented the logging aspect.
 * 
 * The example classes are trains which drive from one train station to another.
 * 
 * @author mfrank
 *
 */
public class Main {

	public Main() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		// start end point
		TrainStation start = new TrainStation("Chemnitz", new Point(0, 0));
		TrainStation end = new TrainStation("Dresden", new Point(50,50));
		
		// train
		Train re = new Train("RE 5678", start.getLocation());
		
		//set destination
		re.setDestionation(end);
		System.out.println("The distance to the destination is: "+re.getDistanceToDestination()+"km");
		
		// drive to destination
		re.driveToDestination();
	}

}
