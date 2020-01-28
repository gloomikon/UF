package avajlauncher.simulation.flyable;

import avajlauncher.simulation.*;
import avajlauncher.simulation.flyable.*;
import java.util.*;

public class AircraftFactory {
	public Flyable newAircraft(String type, String name, int longitude, int latitude, int height) {
		String aircraft;
		try {
			aircraft = md5ToType(type);
		}
		catch(InvalidMD5Exception e) {
			System.out.println(e);
			System.exit(-1);
			return null;
		}
		try {
			switch (aircraft) {
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
		catch (InvalidCoordinateException e) {
			System.out.println(e);
			System.exit(-1);
			return null;
		}
	}

	public static String md5ToType(String md5) throws InvalidMD5Exception {
		Map<String, String> types = new HashMap<String, String>() {
			{
				put("994736b4f0aec72f6e5ae580051d012f", "Baloon");
				put("Baloon", "Baloon");
				put("554cd647d6b135f7e36ab1214c5e816a", "JetPlane");
				put("JetPlane", "JetPlane");
				put("2ab8b43468e8b92b0fc5c81e70e35a2d", "Helicopter");
				put("Helicopter", "Helicopter");
			}
		};
		if (types.containsKey(md5)) {
			return types.get(md5);
		} else {
			InvalidMD5Exception except = new InvalidMD5Exception("Unrecognised Aircraft");
			throw except;
		}
	}
}
