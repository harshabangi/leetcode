import java.util.*;
import java.text.*;
import java.lang.*;


public class Main {
    public static void main(String[] args) {
        SimpleDateFormat myFormat = new SimpleDateFormat("yyyymmdd HH"); //Declaring the date format
        Scanner sc = new Scanner(System.in);

//Getting Input dates from user
        System.out.print("Enter a startdate in format (yyyymmdd HH): ");
        String inputString1 = sc.nextLine();
        System.out.print("Enter a startdate in format (yyyymmdd HH): ");
        String inputString2 = sc.nextLine();


//Checking for valid input date
        if (!isDateValid(inputString1)) {
            System.out.println("Invalid Date Input");
            System.exit(0);
        }


        try {
            //Converting input strings to Date format
            Date date1 = myFormat.parse(inputString1);
            Date date2 = myFormat.parse(inputString2);

            //Checking whether Start date comes before end date
            if (date1.compareTo(date2) > 0) {
                System.out.println("End date should not be less than start date");
                System.exit(0);
            }
            getHoursBetweenDates(date1, date2); //Calling function to print inbetween hours
        } catch (ParseException e) {
            e.printStackTrace();
        }
    }

    public static void getHoursBetweenDates(Date startdate, Date enddate) {

        Calendar calendar = new GregorianCalendar();
        calendar.setTime(startdate);
        //Defining dateformat
        DateFormat dateFormat = new SimpleDateFormat("yyyymmdd HH");
        DateFormat dateFormat2 = new SimpleDateFormat("yyyymmdd ");
        //converting dates into the given format
        String start = dateFormat.format(startdate);
        String end = dateFormat.format(enddate);

        System.out.println("\nList all the hours in between the given hours:\n");

        while (calendar.getTime().before(enddate)) {
            //Iterating inbetween dates
            Date date = calendar.getTime();


            if (date.getDay() == startdate.getDay() || date.getDay() == enddate.getDay()) {
                //if iterating date is start date or end date we print the date with hours
                String strDate = dateFormat.format(date);
                System.out.println(strDate);
                calendar.add(Calendar.HOUR_OF_DAY, 1);
            } else {
                // Just print the inbetween dates without hours
                String strDate = dateFormat2.format(date);
                System.out.println(strDate);
                calendar.add(Calendar.DATE, 1);
            }

        }

        System.out.println(end);

    }

    //Function to check Date is valid or Not
    final static String DATE_FORMAT = "yyyymmdd HH";

    public static boolean isDateValid(String date) {

        try {
            DateFormat df = new SimpleDateFormat(DATE_FORMAT);
            df.setLenient(false);
            df.parse(date);
            return true;
        } catch (ParseException e) {
            return false;
        }
    }
}