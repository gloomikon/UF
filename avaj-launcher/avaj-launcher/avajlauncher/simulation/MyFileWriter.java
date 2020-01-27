package avajlauncher.simulation;

import java.io.*;

public class MyFileWriter {
	public static MyFileWriter writer = new MyFileWriter();
	private static PrintWriter printWriter;

	private MyFileWriter() {
		try {
			final File file = new File("simulation.txt");
			if (!file.exists()) {
				file.createNewFile();
			}
			printWriter = new PrintWriter(file);
		} catch (final IOException e) {
			System.out.println("MyFileWriter Error: " + e);
		}
	}

	public static MyFileWriter getWriter() {
		if (writer == null) {
			writer = new MyFileWriter();
		}
		return (writer);
	}

	public void write(final String str) {
		printWriter.println(str);
	}

	public void close() {
		printWriter.close();
	}
}
