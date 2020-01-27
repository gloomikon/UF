package avajlauncher.simulation.flyable;

import avajlauncher.weather.*;
import avajlauncher.simulation.*;
import java.util.*;

public class Baloon extends Aircraft implements Flyable {
	WeatherTower weatherTower;

	Baloon(String name, Coordinates coordinates) {
		super(name, coordinates);
	}

	public void updateConditions() throws MyException {
		Map<String, String> messages = new HashMap<String, String>() {
			{
				put("RAIN", "Ehhh, I knew I should have to fix these wipers...");
				put("SUN", "This is hot.");
				put("FOG", "May god bless the radar.");
				put("SNOW", "My rotor is going to freeze!");
			}
		};

		String weather = weatherTower.getWeather(coordinates);
		MyFileWriter.writer.write("Baloon#" + name + "(" + id + "): " + messages.get(weather));

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
			MyFileWriter.writer.write("Baloon#" + name + "(" + id + "): landing.");
			weatherTower.unregister(this);
		}
	}

	public void registerTower(WeatherTower weatherTower) {
		this.weatherTower = weatherTower;
	}
}