package avajlauncher.weather;

import avajlauncher.simulation.*;
import avajlauncher.simulation.flyable.*;

public class WeatherTower extends Tower {
	public String getWeather(Coordinates coordinates) {
		return WeatherProvider.getProvider().getCurrentWeather(coordinates);
	}

	public void changeWeather() {
		conditionsChanged();
	}

	public void registering(Flyable flyable) {
		register(flyable);
		flyable.registerTower(this);
	}
}
