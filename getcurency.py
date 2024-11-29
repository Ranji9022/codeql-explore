class CurrencyConverter:
    def __init__(self, exchange_rates):
        self.exchange_rates = exchange_rates

    def convert(self, amount, from_currency, to_currency):
        """Converts an amount from one currency to another.

        Args:
            amount: The amount to convert.
            from_currency: The source currency.
            to_currency: The target currency.

        Returns:
            The converted amount.
        """

        if from_currency not in self.exchange_rates or to_currency not in self.exchange_rates:
            raise ValueError("Invalid currency codes.")

        rate = self.exchange_rates[to_currency] / self.exchange_rates[from_currency]
        return amount * rate

# Example usage:
exchange_rates = {
    "USD": 1.0,
    "EUR": 0.9,
    "GBP": 0.8,
    "JPY": 140.0
}

converter = CurrencyConverter(exchange_rates)

amount_to_convert = 100
from_currency = "USD"
to_currency = "JPY"

converted_amount = converter.convert(amount_to_convert, from_currency, to_currency)
print(f"{amount_to_convert} {from_currency} is equal to {converted_amount} {to_currency}")
