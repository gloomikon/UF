package avajlauncher.simulation.weather;

import avajlauncher.simulation.flyable.*;
import avajlauncher.simulation.*;
import java.util.*;

public class Tower {
	private List<Flyable> observers = new ArrayList<Flyable>();

	public void register(Flyable flyable) {
		observers.add(flyable);
		if (flyable instanceof Helicopter) {
			MyFileWriter.writer.write("Tower says: Helicopter#" 
									+ ((Helicopter) flyable).getName()
									+ "(" + ((Helicopter) flyable).getId()
									+ ") registered to weather tower");
		}
	}

	public void unregister(Flyable flyable) {
		if (observers.contains(flyable)) {
			if (flyable instanceof Helicopter) {
				MyFileWriter.writer.write("Tower says: Helicopter#"
				+ ((Helicopter) flyable).getName()
				+ "(" + ((Helicopter) flyable).getId() + ") unregistered from weather tower");
			}
			observers.remove(flyable);
		}
	}

	protected void conditionsChanged() throws MyException {
		for (Flyable obs : observers) {
			obs.updateConditions();
		}
	}
}