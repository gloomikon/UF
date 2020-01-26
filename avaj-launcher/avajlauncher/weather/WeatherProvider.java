package avajlauncher.simulation.weather;

import avajlauncher.simulation.*;
import java.util.*;

public class WeatherProvider {
	private static final WeatherProvider weatherProvider = new WeatherProvider();
	private static String[] weather = {
		"RAIN",
		"FOG",
		"SUN",
		"SNOW"
	};

	private WeatherProvider() {
	}

	public static WeatherProvider getProvider() {
		return weatherProvider;
	}

	public String getCurrentWeather(Coordinates coordinates) {
		Random random = new Random();
		int index = (coordinates.getLatitude()
					+ coordinates.getLongitude()
					+ coordinates.getHeight()
					+ (random.nextInt(50) * 3)) % 4;
		return weather[index];
	}
}