package avajlauncher.simulation.flyable;

import avajlauncher.weather.*;
import avajlauncher.simulation.*;

public interface Flyable
{
	public void updateConditions() throws InvalidCoordinateException;
	public void registerTower(WeatherTower WeatherTower);
}
