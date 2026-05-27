import yfinance as yf
import pandas as pd
import time

# 取得個股公司資料的語法，先測試一檔看看
stk_basic_data = yf.Ticker('AAPL').info
info_columns = list(stk_basic_data.keys())
print(info_columns)