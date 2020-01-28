package avajlauncher.simulation;

public class Coordinates {
	private int longitude;
	private int latitude;
	private int height;

	public Coordinates(int longitude, int latitude, int height) throws InvalidCoordinateException {
		if (latitude <= 0 || longitude <= 0 || height < 0) {
			InvalidCoordinateException except = new InvalidCoordinateException("Value can not be negative");
			throw except;
		}
		this.longitude = longitude;
		this.latitude = latitude;
		this.height = height > 100 ? 100 : height;
	}

	public int getLongitude() {
		return longitude;
	}

	public int getLatitude() {
		return latitude;
	}

	public int getHeight() {
		return height;
	}

	public void changeLongitudeBy(int value) throws InvalidCoordinateException {
		longitude += value;
		if (longitude < 0) {
			InvalidCoordinateException except = new InvalidCoordinateException("Value can not be negative");
			throw except;
		}
	}

	public void changeLatitudeBy(int value) throws InvalidCoordinateException {
		latitude += value;
		if (latitude < 0) {
			InvalidCoordinateException except = new InvalidCoordinateException("Value can not be negative");
			throw except;
		}
	}

	public void changeHeightBy(int value) {
		height += value;
		if (height > 100) {
			height = 100;
		}
	}
}
