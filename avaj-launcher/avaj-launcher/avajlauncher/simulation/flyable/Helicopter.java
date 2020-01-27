package avajlauncher.simulation.flyable;

import avajlauncher.weather.*;
import avajlauncher.simulation.*;
import java.util.*;

public class Helicopter extends Aircraft implements Flyable {
	WeatherTower weatherTower;

	Helicopter(String name, Coordinates coordinates) {
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
		MyFileWriter.writer.write("Helicopter#" + name + "(" + id + "): " + messages.get(weather));

		switch (weather) {
		case "SUN":
			coordinates.changeLongitudeBy(10);
			coordinates.changeHeightBy(2);
			break;
		case "RAIN":
			coordinates.changeLongitudeBy(5);
			break;
		case "FOG":
			coordinates.changeLongitudeBy(1);
			break;
		case "SNOW":
			coordinates.changeHeightBy(-12);
			break;
		default:
			break;
		}
		if (coordinates.getHeight() < 0) {
			MyFileWriter.writer.write("Helicopter#" + name + "(" + id + "): landing.");
			weatherTower.unregister(this);
		}
	}

	public void registerTower(WeatherTower weatherTower) {
		this.weatherTower = weatherTower;
	}
}