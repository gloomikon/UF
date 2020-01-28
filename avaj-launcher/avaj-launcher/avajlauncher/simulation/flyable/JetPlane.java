package avajlauncher.simulation.flyable;

import avajlauncher.weather.*;
import avajlauncher.simulation.*;
import java.util.*;

public class JetPlane extends Aircraft implements Flyable {
	WeatherTower weatherTower;

	JetPlane(String name, Coordinates coordinates) {
		super(name, coordinates);
	}

	public void updateConditions() throws InvalidCoordinateException {
		Map<String, String> messages = new HashMap<String, String>() {
			{
				put("RAIN", "It's raining. Better watch out for lightings.");
				put("SUN", "I'm melting >_<");
				put("FOG", "See me?");
				put("SNOW", "OMG! Winter is coming!");
			}
		};

		String weather = weatherTower.getWeather(coordinates);
		Simulation.writer.println("JetPlane#" + name + "(" + id + "): " + messages.get(weather));

		switch (weather) {
		case "SUN":
			coordinates.changeLatitudeBy(10);
			coordinates.changeHeightBy(2);
			break;
		case "RAIN":
			coordinates.changeLatitudeBy(5);
			break;
		case "FOG":
			coordinates.changeLatitudeBy(1);
			break;
		case "SNOW":
			coordinates.changeHeightBy(-7);
			break;
		default:
			break;
		}
		if (coordinates.getHeight() < 0) {
			Simulation.writer.println("JetPlane#" + name + "(" + id + "): landing at [" + coordinates.getLongitude() + ", " + coordinates.getLatitude() + "].");
			weatherTower.unregister(this);
		}
	}

	public void registerTower(WeatherTower weatherTower) {
		this.weatherTower = weatherTower;
	}
}
