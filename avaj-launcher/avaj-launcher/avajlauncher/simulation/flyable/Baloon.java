package avajlauncher.simulation.flyable;

import avajlauncher.weather.*;
import avajlauncher.simulation.*;
import java.util.*;

public class Baloon extends Aircraft implements Flyable {
	WeatherTower weatherTower;

	Baloon(String name, Coordinates coordinates) {
		super(name, coordinates);
	}

	public void updateConditions() throws InvalidCoordinateException {
		Map<String, String> messages = new HashMap<String, String>() {
			{
				put("RAIN", "Damn you rain! You messed up my baloon.");
				put("SUN", "Let's enjoy the good weather and take some pics.");
				put("FOG", "Damn it! I can see nothing.");
				put("SNOW", "It's snowing. We're gonna crash.");
			}
		};

		String weather = weatherTower.getWeather(coordinates);
		Simulation.writer.println("Baloon#" + name + "(" + id + "): " + messages.get(weather));

		switch (weather) {
		case "SUN":
			coordinates.changeLongitudeBy(2);
			coordinates.changeHeightBy(4);
			break;
		case "RAIN":
			coordinates.changeHeightBy(-5);
			break;
		case "FOG":
			coordinates.changeHeightBy(-3);
			break;
		case "SNOW":
			coordinates.changeHeightBy(-15);
			break;
		default:
			break;
		}
		if (coordinates.getHeight() < 0) {
			Simulation.writer.println("Baloon#" + name + "(" + id + "): landing at [" + coordinates.getLongitude() + ", " + coordinates.getLatitude() + "].");
			weatherTower.unregister(this);
		}
	}

	public void registerTower(WeatherTower weatherTower) {
		this.weatherTower = weatherTower;
	}
}
