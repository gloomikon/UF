package avajlauncher.simulation;

import avajlauncher.simulation.*;
import avajlauncher.weather.*;
import avajlauncher.simulation.flyable.*;
import java.io.*;
import java.util.*;

public class Simulation {
	public static PrintWriter writer;
	public static void main(String[] args){
		if (args.length != 1) {
			System.out.println("Usage: [java avajlauncher.simulation.Simulation <scenario>]");
			System.exit(-1);
		}
		try {
			File file = new File(args[0]);
			writer = new PrintWriter(new FileWriter("simulation.txt"));
			BufferedReader reader = new BufferedReader(new FileReader(file));
			AircraftFactory factory = new AircraftFactory();
			WeatherTower tower = new WeatherTower();

			String line;
			int count = 0;

			// READ FIRST LINE
			line = reader.readLine();
			if (line == null) {
				System.out.println("File can not be empty!");
				System.exit(-1);
			}
			if (line.isEmpty() == true) {
				System.exit(-1);
			}
			try {
				count = Integer.parseInt(line.trim());
				if (count < 0)
				{
					System.out.println("Simulations count can't be negative!");
					System.exit(-1);
				}
			}
			catch(NumberFormatException e) {
				System.out.println(e);
				System.exit(-1);
			}

			// READ ALL DATA

			while ((line = reader.readLine()) != null) {
				String[] words = line.split(" +|\t+");
				if (words.length != 5) {
					System.out.println("Invalid line: " + line);
					System.exit(-1);
				}
				int longitude = 0;
				int latitude = 0;
				int height = 0;
				try
				{
					longitude = Integer.parseInt(words[2]);
					latitude = Integer.parseInt(words[3]);
					height = Integer.parseInt(words[4]);
				}
				catch(NumberFormatException e) {
					System.out.println(e);
					System.exit(-1);
				}
				tower.registering(factory.newAircraft(words[0], words[1], longitude, latitude, height)) ;
			}

			// BEGIN WORK

			for (int i = 0; i < count; ++i) {
				tower.changeWeather();
			}

			writer.close();
			reader.close();
			System.exit(0);
		}
		catch(IOException e) {
			System.out.println(e);
			System.exit(-1);
		}
	}
}
