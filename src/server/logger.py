import logging
import os


def setup_logger():
    # Create logs directory if it does not exist
    os.makedirs("logs", exist_ok=True)

    logger = logging.getLogger("iot_system")
    logger.setLevel(logging.INFO)

    # Prevent duplicate log handlers
    if logger.handlers:
        return logger

    formatter = logging.Formatter(
        "%(asctime)s | %(levelname)s | %(message)s"
    )

    # Save logs to file
    file_handler = logging.FileHandler(
        "logs/system.log",
        encoding="utf-8"
    )
    file_handler.setFormatter(formatter)

    # Also show logs in terminal
    console_handler = logging.StreamHandler()
    console_handler.setFormatter(formatter)

    logger.addHandler(file_handler)
    logger.addHandler(console_handler)

    return logger


logger = setup_logger()
