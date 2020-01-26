package avajlauncher.simulation.weather;

import avajlauncher.simulation.*;
import avajlauncher.simulation.flyable.*;

public class WeatherTower extends Tower {
	public String getWeather(Coordinates coordinates) {
		return WeatherProvider.getProvider().getCurrentWeather(coordinates);
	}

	void changeWeather() throws MyException {
		// TODO
	}
}