import React, { Component } from 'react';
import { connect } from 'react-redux'
import { brewBeverage } from '../actions/beverage';

class Beverage extends Component {
    handleClick = () => this.props.onClick();

    render() {
        return (
            <button onClick={this.handleClick}>
                {this.props.title}
            </button>
        );
    }
}

export default connect(
    undefined,
    (dispatch, { id }) => ({
        onClick: () => dispatch(brewBeverage(id)),
    })
)(Beverage);
