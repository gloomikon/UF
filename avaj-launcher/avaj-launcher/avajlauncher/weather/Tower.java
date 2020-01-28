package avajlauncher.weather;

import avajlauncher.simulation.flyable.*;
import avajlauncher.simulation.*;
import java.util.*;

public class Tower {
	private List<Flyable> observers = new ArrayList<Flyable>();

	public void register(Flyable flyable) {
		observers.add(flyable);
		if (flyable instanceof Helicopter) {
			Simulation.writer.println("Tower says: Helicopter#" + ((Helicopter) flyable).getName() + "("
					+ ((Helicopter) flyable).getId() + ") registered to weather tower.");
		} else if (flyable instanceof Baloon) {
			Simulation.writer.println("Tower says: Baloon#" + ((Baloon) flyable).getName() + "("
					+ ((Baloon) flyable).getId() + ") registered to weather tower.");
		} else if (flyable instanceof JetPlane) {
			Simulation.writer.println("Tower says: JetPlane#" + ((JetPlane) flyable).getName() + "("
					+ ((JetPlane) flyable).getId() + ") registered to weather tower.");
		}
	}

	public void unregister(Flyable flyable) {
		if (observers.contains(flyable)) {
			if (flyable instanceof Helicopter) {
				Simulation.writer.println("Tower says: Helicopter#" + ((Helicopter) flyable).getName() + "("
						+ ((Helicopter) flyable).getId() + ") unregistered from weather tower");
			} else if (flyable instanceof Baloon) {
				Simulation.writer.println("Tower says: Baloon#" + ((Baloon) flyable).getName() + "("
						+ ((Baloon) flyable).getId() + ") unregistered from weather tower");
			} else if (flyable instanceof JetPlane) {
				Simulation.writer.println("Tower says: JetPlane#" + ((JetPlane) flyable).getName() + "("
						+ ((JetPlane) flyable).getId() + ") unregistered from weather tower");
			}
			observers.remove(flyable);
		}
	}

	protected void conditionsChanged() {
		try {
			if (observers.isEmpty() == false) {
				for (int i = 0; i < observers.size(); i++) {
					observers.get(i).updateConditions();
				}
			}
		} catch (InvalidCoordinateException e) {
			System.out.println(e);
			System.exit(-1);
		}
	}
}
