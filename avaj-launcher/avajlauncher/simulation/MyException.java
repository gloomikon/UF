package avajlauncher.simulation;

public class MyException extends Exception {
	private static final long serialVersionUID = 1L;

	private MyException() {

	}

	public MyException(String str) {
		super(str);
	}
}
