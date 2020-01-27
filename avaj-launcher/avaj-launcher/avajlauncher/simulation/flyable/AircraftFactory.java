package avajlauncher.simulation.flyable;

import avajlauncher.simulation.*;
import avajlauncher.simulation.flyable.*;
public class AircraftFactory {
	public Flyable newAircraft(String type, String name, int longitude, int latitude, int height) throws MyException {
		// TODO: MD5
		switch (type) {
		case "Baloon":
			return new Baloon(name, new Coordinates(longitude, latitude, height));
		case "Helicopter":
			return new Helicopter(name, new Coordinates(longitude, latitude, height));
		case "JetPlane":
			return new JetPlane(name, new Coordinates(longitude, latitude, height));
		default:
			System.out.println("Invalid type: " + type + ". Terminating.");
			System.exit(-1);
			return null;
		}
	}
}
